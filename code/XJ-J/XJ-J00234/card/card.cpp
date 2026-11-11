#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n, m, t=0, flag, length;
    cin >> n >> m;
    vector<int> a(n,0);
	vector<int> cnt(m+1,0);
    
    for(int i = 0; i <= n; i ++){
    	cin >> a[i];
    	length ++;
	}
	for(int l = 0; l < length; l++){
		n = length-l;
		//cout << n << ">>>" << endl;
		for(int i = n; i < length; i ++){
    		flag = 0;
    		for(int j = 0; j < i-1; j++){
    			if(flag = 0){
    				if(a[j] = a[i-1] && a[j] != -1 && a[j] != 0){
    					flag = 1;
    					a[j] = -1;
					}
				} else {
					a[j] = -1;
				}
			}//cout << a[i-1] << endl;
		}//cout << "---" << endl;
		for(int type = 1; type <= m; type++){
			for(int index = n; index < length; index++){
				if(a[index] == type){
					cnt[type-1] ++;
				}
			}
		}
	}
	for(int p = 0; p < m; p++){
		cout << cnt[p] << " ";
	}
    return 0;
}
