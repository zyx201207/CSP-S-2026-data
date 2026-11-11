#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long n,a[N];
long long ans,al,mid,sum,c[N],d[N];
char b[N],c1[N],d1[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
       cin>>a[i]>>b[i];
       al+=a[i];
    }
    if(n==1){
        cout<<0;
    }
    long m1id=al/2;
    for(int i=1;i<=n;i++){
        sum+=a[i];
        if(m1id<sum){
            mid=max(i,1);
            break;
        }
    }
    for(int i=1;i<=mid-1;i++){
        c[i]=a[i]+c[i-1];
        c1[i]=b[i];
    }
    for(int i=n;i>=mid+1;i--){
        d[n-i+1]=a[i]+d[n-i];
        d1[n-i+1]=b[i];
    }
    int l=1,r=1,L=mid-1,R=n-mid;
    long long no=0;
	while(l<=L&&r<=R){
		if(c[l]==d[r]){
			if(c1[l]!=d1[r]){
				ans=ans+d[r]-no;
			}
			no=d[r];
			l+=1;
			r+=1;
		}
		else if(c[l]>d[r]){
			if(c1[l]!=d1[r]){
				ans=ans+d[r]-no;
			}
			no=d[r];
			r+=1;
		}
		else{
			if(c1[l]!=d1[r]){
				ans=ans+c[l]-no;
			}
			no=c[l];
			l+=1;
		}
	}
	int pd=0;
	if(l<=L||c[l]>no){
		pd=1;
	}
	else if(r<=R||d[l]>no){
		pd=2;
	}
	if(pd==1){
		if(c1[l]!=b[mid]){
			ans=ans+(c[l]-no);
		}
		l+=1;
		for(int i=l;i<=L;i++){
			if(c1[i]!=b[mid]){
				ans+=c[i]-c[i-1];
			}
		}
	}
	else if(pd==2){
		if(d1[r]!=b[mid]){
			ans=ans+d[r]-no;
		}
		r+=1;
		for(int i=r;i<=R;i++){
			if(d1[i]!=b[mid]){
				ans+=d[i]-d[i-1];
			}
		}
	}
	cout<<ans<<'\n';
    return 0;
}
