#include<bits/stdc++.h>
using namespace std;
long long a[200010];
long long sta[200010];//a[i]开始处（含） 
char c[200010];
long long s=0;
int n;
int findd(long long u){
	int l=0,r=n+1;
	while(l+1<r){
		int mid=(l+r)/2;
		if(sta[mid]>u){
			r=mid;
		}else{
			l=mid;
		} 
	}
	return r-1;
}
long long abc(long long x,long long y,char cc){
	//cout<<x<<" "<<y<<" "<<cc<<endl;
	long long nowx=x;
	long long ss=0;
	while(1){
		int nowxs=findd(nowx);
		long long nowy=min(sta[nowxs]+a[nowxs]-1,y);
		//cout<<nowx<<" "<<nowy<<endl;
		if(c[nowxs]!=cc){
			ss=ss+(nowy-nowx+1);
		}
		if(nowy==y){
			break;
		}
		nowx=nowy+1;
	}
	return ss;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sta[i]=s+1;
		s+=a[i];
	}
	long long mid;
	long long ans=0;
	mid=s/2;
//	long long noww=0;//当前是第几位 
	long long nows=1;//当前是第几个 
	while(1){
		//cout<<"当前是第"<<nows<<"个，"; 
		long long endd=min(mid,sta[nows]+a[nows]-1);//终点
		//cout<<"endd="<<endd<<endl;
		ans+=abc(s-endd+1,s-sta[nows]+1,c[nows]);
		//cout<<"ans更新为"<<ans<<endl;
		//cout<<endd<<"  !  "<<mid<<endl; 
		if(endd==mid){
			break;
		}
		nows++;
	}
	cout<<ans<<endl;
	return 0;
}

