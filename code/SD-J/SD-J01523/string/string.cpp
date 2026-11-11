#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node{
	ll len;
	char c;
};
ll n;
Node a[2000005];
ll pos1,pos2;
Node n1[2000005],n2[2000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin>>n;
	
	ll slen=0;
	
	for(ll i=1;i<=n;i++){
		cin>>a[i].len>>a[i].c;
		slen+=a[i].len; 
	}
	
	ll mlen=slen/2;
	
	ll tlen=0;
	for(ll i=1;i<=n;i++){
		//cout<<tlen<<"\n";
		if(tlen+a[i].len<mlen){
			tlen+=a[i].len;
		}else if(tlen+a[i].len==mlen){
			//cout<<"!!!!!!\n";
			tlen+=a[i].len;
			pos1=i;
			for(ll j=1;j<=pos1;j++){
				n1[j]=a[j];
			}
			if(mlen*2==slen){
				for(ll j=i+1;j<=n;j++){
					n2[++pos2]=a[j];
				}
			}else{
				if(a[i+1].len==1){
					for(ll j=i+2;j<=n;j++){
						n2[++pos2]=a[j];
					}
				}else{
					for(ll j=i+1;j<=n;j++){
						n2[++pos2]=a[j];
					}
					n2[1].len--;
				}
			}
			break;
		}else if(tlen+a[i].len>mlen){
			pos1=i;
			for(ll j=1;j<=pos1;j++){
				n1[j]=a[j];
			}
			n1[pos1].len=mlen-tlen;
			if(mlen*2==slen){
				pos2=1;
				n2[1].len=a[i].len-n1[pos1].len;
				n2[1].c=a[i].c;
				for(ll j=i+1;j<=n;j++){
					n2[++pos2]=a[j];
				}
			}else{
				if(a[i].len-n1[pos1].len==1){
					for(ll j=i+1;j<=n;j++){
						n2[++pos2]=a[j];
					}
				}else{
					pos2=1;
					n2[1].len=a[i].len-n1[pos1].len-1;
					n2[1].c=a[i].c;
					for(ll j=i+1;j<=n;j++){
						n2[++pos2]=a[j];
					}
				}
			}
			break;
		}
	}
//	for(ll i=1;i<=pos1;i++){
//		cout<<n1[i].len<<n1[i].c;
//	}
//	cout<<"\n";
//	for(ll i=1;i<=pos2;i++){
//		cout<<n2[i].len<<n2[i].c;
//	}

	ll len1=pos1,len2=pos2;
	pos1=1;
	pos2=len2;
	ll ans=0;
	while(1){
		if(n1[pos1].c==n2[pos2].c){
			if(n1[pos1].len<n2[pos2].len){
				n2[pos2].len-=n1[pos1].len;pos1++;
			}else if(n1[pos1].len>n2[pos2].len){
				n1[pos1].len-=n2[pos2].len;pos2--;
			}else{
				pos1++;pos2--;
			}
		}else{
			if(n1[pos1].len<n2[pos2].len){
				n2[pos2].len-=n1[pos1].len;ans+=n1[pos1].len;pos1++;
			}else if(n1[pos1].len>n2[pos2].len){
				n1[pos1].len-=n2[pos2].len;ans+=n2[pos2].len;pos2--;
			}else{
				ans+=n1[pos1].len;
				pos1++;pos2--;
			}
		}
		if(pos1>n&&pos2<1){
			break;
		}
	}
	cout<<ans;
	return 0;
}
/*

4
2 a
3 b
2 c
4 a

*/

//9:52


//froepen
// tarvel
// .ans
// bits\stdc++.h
// slf xuchuhan0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
