#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,len,cnt;
string s;
struct P{
	ll num;
	char c;
}a[200005],b[200005],d[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i].num>>a[i].c;
		len+=a[i].num;	
	}
	ll sum=0;
//	if(len%2==1){
//	    for(int i=1;i<=n;i++){
//	    	if(sum+a[i].num>len/2){
//	    	    a[i].num--;
//				len--;
//				break;	
//	    	}
//	    	sum+=a[i].num;
//	    }
//    cout<<len<<" \n";
//	    for(int i=1;i<=n;i++){
//	    	cout<<a[i].num<<" "<<a[i].c<<"\n";
//		}
//	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i].num;j++){
			s+=a[i].c;
		}
	}
//	cout<<s<<" \n";
	if(len%2==0){
		for(ll i=0,j=len-1;i<=len/2,j>=len/2;i++,j--){
		    if(s[i]!=s[j]) cnt++;
	    }
	cout<<cnt;
	}else{
		for(ll i=0,j=len-1;i<=len/2,j>len/2;i++,j--){
		    if(s[i]!=s[j]) cnt++;
	    }
	    cout<<cnt;
	}
	
//    sum=0;
//	for(int i=1;i<=n;i++){
//		if(sum+a[i].num>len/2){
//			a[i].num-=(len/2-sum)*2;
//			len-=(len/2-sum)*2;
//			break;
//		}
//		sum+=a[i].num;
//		
//	}
//	cout<<len<<" \n";
//	    for(int i=1;i<=n;i++){
//       	    cout<<a[i].num<<" "<<a[i].c<<"\n";
//		}
//    sum=0;
//    ll i1=1;
//    while(sum<=len/2){
//    	b[i1].num=a[i1].num;
//    	b[i1].c=a[i1].c;
//    	d[i1].num=a[len-i1+1].num;
//    	d[i1].c=a[len-i1+1].c;
//    	sum+=a[i1++];
//	}
	
	return 0;
}
