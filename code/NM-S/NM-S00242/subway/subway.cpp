#include <bits/stdc++.h>
#include<cstdio>
using namespace std;
struct vi{
	vector<int> i;
	vector<int> t;
};
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    unsigned int c,n,m,d,q;
    cin>>c>>n>>d>>q;
    
    unsigned int w[m+1];
    for(int i=1;i<=m;i++){
    	cin>>w[i];
	}
	
	unsigned int k[m];
	vi a[n+1];
	t[m+1];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int xxxx;
			cin>>xxxx;
			a[xxxx].i.push_back()=i;
			cin>>a[xxxx].t.push_back();
		}
	}
	
	unsigned int x[m],y[m];
	for(int r=1;r<q;r++){
		cin>>x[r]>>y[r];
		long long ans=0;
		ans+=w[x[r]];
	}
	//w,t-->time
	//a[i]-->m[v]<--a[i]<--n
	//        +
	//       w[v]
	//m<d
	
    return 0;
}
