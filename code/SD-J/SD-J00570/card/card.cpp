#include<bits/stdc++.h>
#define Endl endl
#define endl "\n"
#define For for
using namespace std;
int n,m,arr[200010],cnt[100010],spare[100010],x;
stack<int> st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> arr[i];
	}
	for(int i = 1;i <= n;i++){
		memset(spare,0,sizeof(spare));
		for(int j = i;j <= n;j++){
			if(spare[arr[j]] == 0){
				st.push(arr[j]);
				spare[arr[j]]++;
			}else{
				while(1){
					x = st.top();
					spare[x] = 0;
					st.pop();
					if(x == arr[j]){
						break;
					}
				}
				st.push(arr[j]);
				spare[arr[j]]++;
			}
		}
		while(!st.empty()){
			x = st.top();
			cnt[x]++;
			st.pop();
		}
	}
	for(int i = 1;i <= m;i++){
		cout << cnt[i] << " ";
	}
	
	return 0;
} 
