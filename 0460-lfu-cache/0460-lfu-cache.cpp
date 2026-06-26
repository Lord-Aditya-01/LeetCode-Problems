class LFUCache {
    int cap;
    int minFreq;

    unordered_map<int, pair<int,int>> mp;
    unordered_map<int, list<int>> freqList;
    unordered_map<int, list<int>::iterator> pos;

    void updateFreq(int key){
        int value = mp[key].first;
        int freq = mp[key].second;

        freqList[freq].erase(pos[key]);

        if(freqList[freq].empty()){
            freqList.erase(freq);
            if(minFreq == freq)
                minFreq++;
        }

        // Increase frequency
        freq++;

        mp[key] = {value, freq};

        freqList[freq].push_front(key);
        pos[key] = freqList[freq].begin();
    }

public:
    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;

        updateFreq(key);
        return mp[key].first;
    }

    void put(int key, int value) {

        if(cap == 0)
            return;

        // Key already exists
        if(mp.find(key) != mp.end()){
            mp[key].first = value;
            updateFreq(key);
            return;
        }

        // Cache full
        if(mp.size() == cap){
            int delKey = freqList[minFreq].back();

            freqList[minFreq].pop_back();

            if(freqList[minFreq].empty())
                freqList.erase(minFreq);

            mp.erase(delKey);
            pos.erase(delKey);
        }

        // Insert new key
        mp[key] = {value, 1};
        freqList[1].push_front(key);
        pos[key] = freqList[1].begin();
        minFreq = 1;
    }
};