#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
struct{
	int l;
	char idex;
}b[200005],d[200005];
char c[200005];
long long len,ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	len/=2;
	long long len1=0;
	for(int i=1;i<=n;i++){
		if(len1+a[i]>=len){
			b[i].l=len-len1;
			b[i].idex=c[i];
//			cout<<i<<" "<<b[i].l<<" "<<b[i].idex<<"\n";
			break;
		}else{
			len1+=a[i];
			b[i].l=a[i];
			b[i].idex=c[i];
//			cout<<b[i].l<<" "<<b[i].idex<<"\n";
		}
	}
	long long len2=0;
	for(int i=n;i>=1;i--){
		if(len2+a[i]>=len){
			d[n-i+1].l=len-len2;
			d[n-i+1].idex=c[i];
//			cout<<n-i+1<<" "<<d[n-i+1].l<<" "<<d[n-i+1].idex<<"\n";
			break;
		}else{
			len2+=a[i];
			d[n-i+1].l=a[i];
			d[n-i+1].idex=c[i];
//			cout<<n-i+1<<" "<<d[n-i+1].l<<" "<<d[n-i+1].idex<<"\n";
		}
	}
//	for(int i=1;i<=n;i++){
//		cout<<i<<" "<<b[i].l<<" "<<b[i].idex<<"\n";
//		cout<<i<<" "<<d[i].l<<" "<<d[i].idex<<"\n";
//	}
	int i=1,j=1;
	while(b[i].l&&d[j].l){
		if(b[i].idex==d[j].idex){
			if(b[i].l>d[j].l){
				b[i].l-=d[j].l;
				j++;
			}else if(b[i].l==d[j].l){
				i++,j++;
			}else{
				d[j].l-=b[i].l;
				i++;
			}
		}else{
			if(b[i].l>d[j].l){
				b[i].l-=d[j].l;
				ans+=d[j].l;
				j++;
			}else if(b[i].l==d[j].l){
				ans+=d[j].l;
				i++,j++;
			}else{
				d[j].l-=b[i].l;
				ans+=b[i].l;
				i++;
			}
		}
	}
	cout<<ans;
	return 0;
}