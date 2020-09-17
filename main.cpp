class ConvexHull{
    public :
    vector<vector<ll>> st;
    // st takes { intercept, slope , leftmost_point of the segment , index of the interval in the array }
    void add(ll intercept,ll slope,ll index){
        if(st.empty()){
            st.pb({intercept,slope,-LLONG_MAX,index});
            return ;
        }
        while((int)st.size() > 1){
            vector<ll> x = st.back();
            vector<ll> y = st[(int)st.size()-2];
            ll pt = (y[0] - intercept)/ (slope - y[1]);
            if(pt <= x[2]){
                st.pop_back();
            }
            else{
                break;
            }
        }
        vector<ll> x = st.back();
        ll leftmostPoint = (x[0] - intercept) / (slope - x[1]);
        st.push_back({intercept,slope,leftmostPoint,index});
    }
    ll get(ll point){
        ll lo = -1,hi = (int)st.size();
        while(hi - lo > 1){
            ll mid = (lo+hi)/2;
            if(st[mid][2] <= point){
                lo = mid;
            }
            else{
                hi = mid;
            }
        }
        return st[lo][3];
    }
};
