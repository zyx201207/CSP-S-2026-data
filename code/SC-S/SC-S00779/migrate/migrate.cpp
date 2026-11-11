#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t;
ll n[100010],d[100010];
ll l[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==13 || c==14) {
		for(int i=1;i<=t;i++){
			cin>>n[i]>>d[i];
			cout<<endl;
			memset(l,0,sizeof(l));
			for(int j=1;j<=n[i];j++){
				cin>>l[j];
					
			}
			ll ca=l[2]-l[1];
		cout<<l[n[i]]/(d[i]-1)*ca<<endl;
		}
	}
	else{
		for(int i=1;i<=t;i++){
		cin>>n[i]>>d[i];
		cout<<endl;
		memset(l,0,sizeof(l));
		for(int j=1;j<=n[i];j++){
			cin>>l[j];
				
		}
		int cnt;
		for(int j=l[1];j>=l[n[i]]-d[i];j++){
			if(l[j]-d[i]<l[j-2] && l[j]-d[i]>l[j-3]){
				cnt++;
			}
		}
		cout<<cnt<<"\n";
	}
	}
	
	
	
	return 0;
}


