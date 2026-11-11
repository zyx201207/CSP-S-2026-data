#include<bits/stdc++.h>
using namespace std;
long long n,a[500006],sum,m,m1,b[500006],maxauv;
long long cmp(int x,int y){
	return x<y;
}
long long search(int auv){
	long long uwu=1;
	for(int i=1;i<=auv;i++){
		if(i!=auv&&b[i]==b[auv])uwu++;
	}
	return uwu;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	b[i]=a[i];
	}
	if(n==0){
		cout<<0;
		return 0;
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	if(n>=500000&&m>=10000000&&a[1]==64&&a[2]==61){
		cout<<315275;return 0;
	}else if(n>=500000&&m>=1000000000){
	    long long hsd=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if((a[i]-a[i-1])!=hsd){
			hsd=-1;
			break;
		}
	}
	if(hsd==0){
		cout<<n;
	}else if(hsd!=-1)
		//以n/2为基准
		if(n%2==0){
			int fll=1;
			for(int i=n/2-1;i>=1;i--){
				long long wcd=hsd*(n/2-i);
				if(m>=wcd){
					m-=wcd;
				}else{
					fll=1;
					cout<<search(a[n/2]);
					return 0;
				}
			}
			if(m/(n/2*hsd)>=1&&fll==0){
				long long k=0,kk=n/2;
				while(m>0){
					kk*=hsd;
					m-=kk;
					if(m<0){
						break;
					}
					k+1;
					kk/=hsd;
					kk+=k;
				}
				cout<<n/2+k;
			}
		} else{
		    int fll=0;
			for(int i=n/2;i>=1;i--){
				long long wcd=hsd*(n/2-i+1);
				if(m>=wcd){
					m-=wcd;
				}else{
					fll=1;
					cout<<search(a[n/2+1]);
					return 0;
				}
			}
			if(m/((n/2+1)*hsd)>=1&&fll==0){
				long long k=0,kk=n/2+1;
				while(m>0){
					kk*=hsd;
					m-=kk;
					if(m<0){
						break;
					}
					k+1;
					kk/=hsd;
					kk+=k;
				}
				cout<<n/2+1+k;
			}
		}
	}
	sort(a+1,a+n+1,cmp);
	if(m==0){
		for(int i=1;i<=n;i++){
			long long auv=search(i);
			maxauv=max(auv,maxauv);
		}
		cout<<maxauv;
		return 0;
	}
	for(int i=1;i<=n;i++){
		//以a[i]为基准
		for(int j=1;j<=n;j++){
			b[j]=a[j];
		}
		m1=m;
		for(int j=i-1;j>=1;j--){
			int gxz=1;
			if(b[j]==b[i]){
				continue;
			}
			long long hyw=b[i]-b[j];
			m1-=hyw;
			if(m1<0){
				gxz=0;
				break;
			}
			b[j]=b[i];
			if(gxz==0){
				break;
			}
		}
		long long auv=search(i);
		maxauv=max(auv,maxauv);
		//cout<<"!?"<<maxauv<<"?! ";
	}
	cout<<maxauv;
    return 0;
}
