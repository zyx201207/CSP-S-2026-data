#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int n,l,ans,cc,z;
string s;
struct node{
	int cnt;
	char d;
}a[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i].cnt>>a[i].d;
    	l+=a[i].cnt;
	}
	if(l%2==0){
	    for(int i=1,j=n;i<=n&&j>=1&&i<=j;){
	    	if(a[i].d==a[j].d){
	    		if(a[i].cnt>a[j].cnt){
	    			a[i].cnt-=a[j].cnt;
					j--;
				}
	    		else if(a[i].cnt<a[j].cnt){
	    			a[j].cnt-=a[i].cnt;
	    			i++;
				}
	    		else{
	    			i++;j--;
	    			a[i].cnt-=a[j].cnt;
	    		}
			}
			else {
				if(a[i].cnt>a[j].cnt){
					ans+=a[j].cnt;
					a[i].cnt-=a[j].cnt;
					j--;
				}
	    		else if(a[i].cnt<a[j].cnt){
	    			ans+=a[i].cnt;
					a[j].cnt-=a[i].cnt;
	    			i++;
				}
	    		else{
	    			ans+=a[j].cnt;
					a[i].cnt-=a[j].cnt;
					i++;j--;
	    		}
			}
		}
		cout<<ans;	
	}
	else{
		z=(l+1)/2;
		for(int i=1;i<=n;i++){
			if(z>a[i].cnt)z-=a[i].cnt;
			else{
				a[i].cnt-=1;
				break;
			}
		}
		for(int i=1,j=n;i<=n&&j>=1&&i<=j;){
	    	if(a[i].d==a[j].d){
	    		if(a[i].cnt>a[j].cnt){
	    			a[i].cnt-=a[j].cnt;
					j--;
				}
	    		else if(a[i].cnt<a[j].cnt){
	    			a[j].cnt-=a[i].cnt;
	    			i++;
				}
	    		else{
	    			i++;j--;
	    			a[i].cnt-=a[j].cnt;
	    		}
			}
			else {
				if(a[i].cnt>a[j].cnt){
					ans+=a[j].cnt;
					a[i].cnt-=a[j].cnt;
					j--;
				}
	    		else if(a[i].cnt<a[j].cnt){
	    			ans+=a[i].cnt;
					a[j].cnt-=a[i].cnt;
	    			i++;
				}
	    		else{
	    			ans+=a[j].cnt;
					a[i].cnt-=a[j].cnt;
					i++;j--;
	    		}
	    		
			}
		}
		cout<<ans;
	}
	return 0;
}//Trick||Treat!
//aabbc