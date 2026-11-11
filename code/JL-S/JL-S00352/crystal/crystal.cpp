

#include<bits/stdc++.h>
using namespace std;

int main(){
    //freopen("crystal3.in", "r", stdin);
    //freopen("crystal3.out", "w", stdout);

	int n, m;
    vector<int> res;
    int j = 0;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
	sort(a.begin(), a.end());
	while(m--){
		++a[j];
		if(a[j] == a[j+1]){
			res.push_back(a[j]);
			res.push_back(a[j+1]);
			++j;
		}
	}
	res.pop_back();
	
	cout << res.size() << endl;
    return 0;
}
