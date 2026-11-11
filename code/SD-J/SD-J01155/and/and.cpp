#include<bits/stdc++.h>
using namespace std;
int n,m;
struct f{
	string s;
	int b;	
}a[100000];
int mx=INT_MIN;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].b;
		mx=max(mx,a[i].b);
		string s2;
		while (a[i].b){
			s2+=a[i].b%2+'0';
			a[i].b/=2;
		}
		for(int j=s2.size()-1;j>=0;j--){
			a[i].s+=s2[j];
		}
	}
	if(m==1) 
	{
		cout<<mx;
		return 0;
	}
	if(m==2){
		mx=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				int l=max(a[i].s.size(),a[j].s.size());
				string ans;
				for(int k=0;k<l;k++){
					if(a[i].s[k]==a[j].s[k]){
						ans+=a[i].s[k];
					}
					else ans+='0';
				}
				cout<<ans<<endl;
				int ant=0;
				for(int k=0;k<ans.size();k++){
					int o=ans[k]-'0';
					for(int c=1;c<=k;c++){
						o*=2;
					}
					ant+=o;
				}
				mx=max(mx,ant);
			}	
		}
	cout<<mx;
	}
	
}
