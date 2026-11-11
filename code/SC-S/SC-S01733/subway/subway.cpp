#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    int c,n,m,d,q,k[3];
    vector<int> a1,t1,a2,t2;
    cin>>c>>n>>m>>d>>q;
    int w[m+7];
    for(int i=1;i<=m;i++)cin>>w[i];
    cin>>k[1]>>k[2];
	for(int i=1;i<=2*k[1];i++){
		int a ,t;
		cin>>a>>t;
		a1.push_back(a);
		t1.push_back(t);
	}
	for(int i=1;i<=2*k[2];i++){
		int a ,t;
		cin>>a>>t;
		a2.push_back(a);
		t2.push_back(t);
	}
	int x,y,t[n+2];
	while(q--){
		cin>>x>>y;
		int sum=w[x]+w[y],k=0,x1,y1;
		for(auto i:a1){
			t[a1[i]]++;
			if(a1[i]==y){
				y1=i;
				k++;
			}
			if(a1[i]==x){
				x1=i;
				k++;
			}
		}
		int kk=0;
		for(auto i:a2){
			t[a2[i]]++;
			if(a2[i]==y){
				y1=i;
				kk++;
			}
			if(a2[i]==x){
				x1=i;
				kk++;
			}
		}
		if(k==2){
			for(int i=x1;i<=y1;i++){
				sum+=t1[i];
			}
			return 0;
		}
		if(kk==2){
			for(int i=x1;i<=y1;i++){
				sum+=t2[i];
			}
	    }
	    cout<<sum<<'\n';
	}
	return 0;
} 