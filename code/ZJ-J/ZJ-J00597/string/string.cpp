#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,mid,f=0,j,i,ans=0;
struct no{
	int s;
	char z;
}a[200005],t;
stack<no> p;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i].s>>a[i].z;
		mid+=a[i].s;
	}
	if(mid%2) f=1;
	mid=(mid+1)/2;
	for(i=1;i<=n;i++){
		if(j+a[i].s>=mid){
			if(f){
				t.s=mid-j-1,t.z=a[i].z;
				//cout<<t.s<<t.z<<" ";
				p.push(t);
				a[i].s=a[i].s+j-mid;
			}else{
				t.s=mid-j,t.z=a[i].z;
				//cout<<t.s<<t.z<<" ";
				p.push(t);
				a[i].s=a[i].s+j-mid;
			}
			break;
		}
		t.s=a[i].s,t.z=a[i].z;
		//cout<<t.s<<t.z<<" ";
		p.push(t);
		j+=a[i].s;
	}
	//cout<<i<<'\n';
	for(;i<=n;i++){
		int mb=a[i].s;
		char pz=a[i].z;
		while(mb){
			t=p.top();
			p.pop();
			int m=t.s;
			char c=t.z;
			//cout<<"1:"<<mb<<pz<<" 2:"<<m<<c<<"\n";
			if(mb<=m){
				if(pz!=c) ans+=mb;
				m-=mb;
				if(m>0){
					t.s=m,t.z=c;
					p.push(t);
				}
				break;
			}else{
				if(pz!=c) ans+=m;
				mb-=m;
			}
		}
		//cout<<ans<<" ";
	}
	//cout<<1111;
	cout<<ans;
	return 0;
}
