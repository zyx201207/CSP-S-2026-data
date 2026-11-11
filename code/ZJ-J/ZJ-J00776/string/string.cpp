#include<bits/stdc++.h>
#define int long long
using namespace std;
struct stu{int l;char s;}a[200005],L[200005],R[200005];
int n,sum,s,k,r,ans,w,j=1,cnt; char now;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].l>>a[i].s,sum+=a[i].l;
	for(int i=1;i<=n;i++){
		if(s+a[i].l>sum/2){L[i]={sum/2-s,a[i].s},k=i;break;} 
		s+=a[i].l,L[i]=a[i];
	}//cout<<k<<' '<<s<<' '<<sum<<"\n\n"; 
	R[1]={s+a[k].l-sum+sum/2,a[k].s};
	for(int i=k+1;i<=n;i++) R[i-k+1]=a[i];
	for(int i=1;i<=k/2;i++) swap(L[i],L[k-i+1]);
//	for(int i=1;i<=k;i++) cout<<L[i].s<<' '<<L[i].l<<'\n';
//	cout<<"\n";
//	for(int i=1;i<=n-k+1;i++) cout<<R[i].s<<' '<<R[i].l<<'\n';
	for(int i=1;i<=n-k+1;i++){
		w=r,r+=R[i].l,now=R[i].s;
//		cout<<i<<":\n";
		while(w<r){
			w+=L[j].l;
//			cout<<r<<' '<<w<<' '<<j<<'\n',cnt++;
			if(L[j].s!=now){
				if(w<r) ans+=L[j].l;else if(w==r) ans+=L[j].l;
				else{ans+=r-w+L[j].l,L[j].l=w-r;break;}
			}else if(w>r){L[j].l=w-r;break;}j++;
		}
	}cout<<ans;
}
/*
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

T2>>>>>>>>T3 
*/ 
