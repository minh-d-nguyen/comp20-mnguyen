vector<vector<int> > anagrams(const vector<string> &A) {
    unordered_multimap<string, int> anagram_groups;
    vector<string> unique_keys;
    vector<vector<int> > ret;
    int len = A.size();
    for (int i = 0; i < len; i++) {
        string key = A[i];
        sort(key.begin(), key.end());
        if (anagram_groups.find(key) == anagram_groups.end()) {
            unique_keys.push_back(key);
        }
        anagram_groups.insert({key, i});
    }
    for (int i = 0; i < unique_keys.size(); i++) {
        auto its = anagram_groups.equal_range(unique_keys[i]);
        if (its.first != its.second) {
            vector<int> indices;
            for (auto it = its.first; it != its.second; ++it) {
                indices.push_back(it->second + 1);
            }
            ret.push_back(indices);
        }
    }
    for (int i = 0; i < ret.size(); i++) {
        sort(ret[i].begin(), ret[i].end());
    }
    return ret;
}