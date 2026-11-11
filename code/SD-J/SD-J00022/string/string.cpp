#include<bits/stdc++.h>
#define ll long long
#define pr priority_queue
#define F first
#define endl "\n"
#define S second
#define pi pair
#define mk make_pair
#define ull unsigned long long
using namespace std;
const int N=2e5+100;
ll a[N],a1[N],a2[N];
char c[N],c1[N],c2[N];
ll cnt=0;
int main(){
//	system("fc string6.ans string.out");
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	cin>>c[i];
    	cnt+=a[i];
	}
	ll cnt1=cnt/2;
	ll sum1=0,l1;
	ll num=0;
	for(int i=1;i<=n;i++){
		sum1+=a[i];
		a1[i]=a[i];
		c1[i]=c[i];
		if(sum1==cnt1){
		    l1=i+1;
			for(int j=n;j>=l1;j--){
				a2[++num]=a[j];
				c2[num]=c[j];
			}
			l1--;
			break;
		}
		else if(sum1>cnt1){
		    l1=i; 
			a1[i]=a1[i]-(sum1-cnt1);
			a[i]=sum1-cnt1;
			for(int j=n;j>=l1;j--){
				a2[++num]=a[j];
				c2[num]=c[j];
			} 
			break;
		}
	}
    if(cnt%2==1){
    	a2[num]--;
    	if(a2[num]==0){
    	    num--;
		}
	} 
//	cout<<endl;
//	int p1=0;
//	for(int i=1;i<=l1;i++){
////		cout<<a1[i]<<' '<<c1[i]<<endl;
//		p1+=a1[i];
//	}cout<<p1<<endl<<endl;p1=0;
//	for(int i=1;i<=num;i++){
////		cout<<a2[i]<<' '<<c2[i]<<endl;
//		p1+=a2[i];
//	}cout<<p1<<endl<<endl; 
    ll num1=0,ans=0;
    ll r1=1;
    for(int i=1;i<=l1;i++){
    	num1+=a1[i];
    	while(num1>0){
    		if(num1>=a2[r1]){
    			num1=num1-a2[r1];
    			if(c1[i]!=c2[r1]){
    				ans=ans+a2[r1];
				}
				r1++;
			}
			else{
				a2[r1]=a2[r1]-num1;
				if(c1[i]!=c2[r1]){
					ans=ans+num1;
				}
				num1=0;
			}
		}
	}
	cout<<ans;
	return 0;
}

