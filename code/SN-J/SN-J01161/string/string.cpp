#include<bits/stdc++.h>
using namespace std;
long long n;
struct node{
	long long s,e,l;
	char c;
}a[20009];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	long long sta=1,en=0;
	for(long long i=1;i<=n;i++){
		long long x;
		char xx;
		cin>>x>>xx;
		a[i].s=sta;
		en+=x;;
		a[i].e=en;
		sta=en+1;
		a[i].c=xx;
		a[i].l=x;
    }
    long long k=1;
    long long ans=0;
    long long w=en/2;
    long long star=1,en2=n;
    while(k<=w){
    	if(star==en){
    		break;
		}else{
			if(a[star].l<a[en2].l){
				if(a[star].c!=a[en2].c){
					ans+=a[star].l;
				}
				k=a[star].e+1;
                a[en2].l-=a[star].l;
                a[en2].e-=a[star].l;
                star++;
			}else if(a[star].l>a[en2].l){
				if(a[star].c!=a[en2].c){
					ans+=a[en2].l;
				}
				k=a[en2].l+a[star].s;
				a[star].l-=a[en2].l;
                a[star].s+=a[star].l;
                en2--;
			}else{
				if(a[star].c!=a[en2].c){
					ans+=a[star].l;
				}
				k=a[star].e+1;
				star++;
				en2--;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
} 
