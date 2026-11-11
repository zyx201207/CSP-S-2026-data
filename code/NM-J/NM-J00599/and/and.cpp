#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long int n,m,ans=0;
	string a[200005];
	cin >> n>>m;
	for(int i =1;i<=n;i++){
		int x;
		string s2,s;
		cin >> x;
		while(x!=0){
			int y=x%2;
			x=x/2;
			s+=y+48;
		}
		for(int j =s.size()-1;j>=0;j--){
			s2+=s[j];
		}
		a[i]=s2;
	}
	for(int i =1;i<=n;i++){
		for(int j =i+1;j<=n;j++){
			int siz=min(a[i].size(),a[j].size());
			int cnt=1;
			long long int ans1=0;
			for(int z=siz-1;z>0;z--){
				if(a[i][z]==a[j][z]&&a[i][z]==1){
					ans1+=cnt;
					
				}
				cnt=cnt*2;
			}
			ans=max(ans1,ans);
		}
	}
	cout <<ans;
	return 0;
}
