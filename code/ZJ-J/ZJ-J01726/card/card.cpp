#include<bits/stdc++.h>
using namespace std;
int n,m;
char a[500005];int cnt[500005];
bool f[500005]={0};
string stk;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int mm=0;
	for(int i=mm;i<n;i++){
		if(f[a[i]-'0']==0){
			stk+=a[i];
		}else{
			for(int j=0;j<stk.size();j++){
				if(stk[j]==a[i]){
					for(int k=j;j<stk.size();k++){
						stk.erase();
					}
				}
			}
		}
		f[a[i]-'0']=1;
		mm++;
		for(int j=0;j<stk.size();j++){
			cnt[stk[j]-'0']++;
		} 
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
