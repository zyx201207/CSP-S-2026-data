#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200010],c[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,len=0,mid=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		char cc;
		cin>>a[i]>>cc;
		c[i]=cc-'a';
		len+=a[i];
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=a[i];
		if(sum>len/2){
			mid=i;
			break;
		}
	}
	for(int i=n;i>mid;i--){
		a[i+1]=a[i];
		c[i+1]=c[i];
	}
	n++;
	a[mid+1]=sum-len/2,a[mid]-=a[mid+1];
	c[mid+1]=c[mid];
	if(len&1){
		a[mid+1]--;
		len--;
	}
	int l=a[1],r=a[n],ans=0;
	int i=1,j=n,nl=c[1],nr=c[n];
	int last=0;
	while(i<=mid&&j>mid){
		if(l<r){
			if(nl!=nr){
				ans+=l-last;
			}
			last=l;
			i++,l+=a[i],nl=c[i];
		}
		else if(l>r){
			if(nl!=nr){
				ans+=r-last;
			}
			last=r;
			j--,r+=a[j],nr=c[j];
		}
		else{
			if(nl!=nr){
				ans+=l-last;
			}
			last=r;
			i++,l+=a[i],nl=c[i];
			j--,r+=a[j],nr=c[j];
		}
	}
	cout<<ans;
	return 0;
}
