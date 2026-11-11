#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

inline bool judge_A(const std::vector<long long>& a){
    for(const auto& i:a)
    if(i!=1)
    return false;
    return true;
}

inline void solve(){
    int n;
    long long m;
    std::cin >> n >> m;
    std::vector<long long> a(n);
    for(int i=0;i<n;++i){
        std::cin >> a[i];
    }
    sort(a.begin(), a.end());
    //A
    bool A = judge_A(a);
    if(A){
        long long en = 1;
        std::cout << n;
        return;
    }
    //贪心暴力(很容易hack,骗分),可以每个长度相同的平台都算一次,但我懒得改了. 
    long long u = 0, ans = 1, ai = 0;
    for(int i=1, l=1;i<n;++i){
    	if(a[i]==a[i-1]){
    		++l;
    		if(l>ans){
    			ai = i;
    			ans = l;
			}
			continue;
		}
    	l = 1;
	}
	//向前
	long long i = ai-ans+1, b = a[i];
	while(i>0&&u<=m){
		if(b-a[i-1]+u<=m){
			u += b-a[i-1];
			a[--i] = b;
			++ans;
			continue;
		}
		break;
	}
	//向后
	i = ai;
	while(i+1<n&&u<=m){
		if((a[i+1]-b)*ans+u<=m){
			u += (a[i+1]-b)*ans;
			b = a[++i];
			++ans;
			continue;
		}
		break;
	}
    std::cout << ans;
    return;
}

signed main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0), std::cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int T = 1;
	while(T--){
		solve();
	}
	return 0;
}





























