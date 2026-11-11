#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=0x3f3f3f3f3f3f3f3f;
int n;
struct part{
	int a;
	char c;
};
part lst[200010];
int index[200010];
char byid(int t){
	return lst[upper_bound(index,index+n,t)-index-1].c;
}
int lcheck(int t){
	int a=upper_bound(index,index+n,t)-index-1;
	if(a<0 || a>=n){
		return -inf;
	}
	return index[a];
}
int rcheck(int t){
	int a=upper_bound(index,index+n,t)-index;
	if(a<0 || a>=n){
		return inf;
	}
	return index[a]-1;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int ix=0;
	for(int i=0;i<n;i++){
		int a;
		char c;
		cin>>a>>c;
		lst[i].a=a;
		lst[i].c=c;
		index[i]=ix;
		ix+=a;
	}
	int l,r;
	if(ix%2==1){
		l=ix/2-1;
		r=ix/2+1;
	}
	else{
		l=ix/2-1;
		r=ix/2;
	}
	int ans=0;
	// if(byid(l)!=byid(r)){
	// 	ans++;
	// }
	while(l>=0){
		int lch=lcheck(l),rch=rcheck(r);
		// if(lch==l || rch==r){
		// 	cout<<l<<" "<<r<<"d1\n";
		// 	if(byid(l)!=byid(r)){
		// 		ans++;
		// 	}
		// 	l--,r++;
		// 	continue;
		// }
		int jump=min(l-lch,rch-r);
		//cout<<l<<" "<<r<<" "<<lch<<" "<<rch<<" "<<jump<<"\n";
		
		// if(l-jump<0 || r+jump>=ix){
		// 	jump=l;
		// 	cout<<"jump="<<l;
		// }
		//cout<<byid(l)<<" "<<byid(r)<<"\n";
		l-=jump;
		r+=jump;
		//cout<<byid(l)<<" "<<byid(r)<<"\n";

		if(byid(l)!=byid(r)){
			ans+=jump+1;
		}
		l--;
		r++;
		if(l<0)break;
		//cout<<byid(l)<<" "<<byid(r)<<"\n";
		// if(byid(l)!=byid(r)){
		// 	ans++;
		// }
	}
	cout<<ans;
	return 0;
}