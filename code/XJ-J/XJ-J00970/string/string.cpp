#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=4e5+10;
int a[N],b[N];
char c[N],d[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0,sum=0,m=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i]>>c[i];
		cnt+=b[i];
	}
	bool f=0;
	if(cnt%2){//JISHU
		cnt/=2;
		for(int i=1;i<=n;i++){
			if(!f&&sum+b[i]>cnt){
				f=1;
				if(cnt-sum==0){
					b[i]--;
					m++;
					a[m]=b[i];
					d[m]=c[i];
				}else{
					m++;
					a[m]=cnt-sum;
					d[m]=c[i];
					if(b[i]-a[m]-1>0){
						m++;
						a[m]=b[i]-1-a[m-1];
						d[m]=c[i];
					}
				}	
			}else{
				m++;
				a[m]=b[i];
				d[m]=c[i];
			}
			sum+=b[i];
		}
	}else{//OUSHU
		cnt/=2;
		for(int i=1;i<=n;i++){
			if(!f&&sum+b[i]>cnt){
				f=1;
				if(cnt-sum==0){
					m++;
					a[m]=b[i];
					d[m]=c[i];
				}else{
					m++;
					a[m]=cnt-sum;
					d[m]=c[i];
					if(b[i]-a[m]>0){
						m++;
						a[m]=b[i]-a[m-1];
						d[m]=c[i];
					}
				}
			}else{
				m++;
				a[m]=b[i];
				d[m]=c[i];
			}
			sum+=b[i];
		}
	}
//	for(int i=1;i<=m;i++){
//		cout<<a[i]<<' '<<d[i]<<'\n';
//	}
	int s=0,e=0,x=0,y=0,ans=0;
	for(int i=1,j=m;;){
		if(x<cnt){
			s+=a[i];
			x+=a[i];
		}
		if(y<cnt){
			e+=a[j];
			y+=a[j];
		}
		int mn=min(a[i],a[j]);
		s-=mn;
		e-=mn;
		if(d[i]!=d[j]){
			ans+=mn;
		}
		if(i+1==j)break;
		if(s<e){
			a[j]=e;
			if(x<cnt)i++;
		}else if(s>e){
			a[i]=s;
			if(y<cnt)j--;
		}else if(s==e){
			if(x<cnt)i++;
			if(y<cnt)j--;
		}
	}
	cout<<ans;
	return 0;
} 
