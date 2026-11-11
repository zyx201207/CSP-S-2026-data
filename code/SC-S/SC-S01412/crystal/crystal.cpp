#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+5;
long long a,s,d,f,g,h,ans,A[N],lzz,rzz;
long long mn(long long q,long long w){
	if(q>=w){
		return w;
	}
	return q;
}
long long mx(long long q,long long w){
	if(q>=w){
		return q;
	}
	return w;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>s;
	for(int i=1;i<=a;i++){
		cin>>A[i];
	}
	for(int i=1;i<=A[a];i++){
		g=0;
		h=s;
		for(int j=1;j<=a;j++){
			if(A[j]<=i){
				lzz=j;
			}
			if(A[j]>=i){
				rzz=j;
				break;
			}
		}
		if(lzz==rzz){
			g++;
		}
		if(s<A[rzz]-A[lzz]){
			if(s<mn(A[rzz]-i,i-A[lzz])){
				continue;
			}
			ans=mx(ans,1);
			continue;
		}while((lzz>=2)&&(rzz<a)&&(h>mn(A[rzz+1]-A[rzz],A[lzz]-A[lzz-1]))){
			if(A[rzz+1]-A[rzz]>A[lzz]-A[lzz-1]){
				lzz--;
				g++;
				h-=(A[lzz+1]-A[lzz]);
			}
			else{
				rzz++;
				h-=(A[rzz]-A[rzz-1]);
				g++;
			}
		}
		//cout<<i<<' '<<lzz<<" "<<rzz<<" ";
		//g=rzz-lzz;
		if(lzz<1){
			while(A[rzz+1]-A[rzz]<=h&&rzz<a){
				h-=A[rzz+1]-A[rzz];
				rzz++;
				g++;
			}
		}
		if(rzz>a){
			while(A[lzz]-A[lzz-1]<=h&&lzz>1){
				h-=A[lzz]-A[lzz-1];
				g++;
				lzz--;
			}
		}
		ans=mx(ans,g);
		//cout<<g<<endl;
	}
	cout<<ans;
	return 0;
}