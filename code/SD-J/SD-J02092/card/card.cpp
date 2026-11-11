#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,a[300005];

int t2[300005]={0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	//cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++)cin >> a[i];
	for(int i=1;i<=n;i++){
		int t[300005]={0};//ÅÆµÄÏÂ±ê 
		for(int j=i;j<=n;j++){
			if(t[a[j]]==0){
				t[a[j]]=j;
			}else{
				int xa=t[a[j]];
				for(int k=t[a[j]]+1;k<=j;k++){
					//cout << a[k] << " ";
					t[a[k]]=0;
				}
				t[a[j]]=xa;
				//cout << endl;
			}
		}
		bool f[300005]={0};
		for(int j=i;j<=n;j++){
			if(t[a[j]]!=0&&f[a[j]]==0){
				t2[a[j]]++;
				f[a[j]]=1;
				//cout << a[j] << " ";
			}
		}
		//cout << endl;
	}
	for(int i=1;i<=m;i++){
		cout << t2[i] << " ";
	}
	return 0;
}
