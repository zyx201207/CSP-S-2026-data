#include<bits/stdc++.h>
using namespace std;
long long n,a[1000000],f,ans,cnt;
char c[1000005]; 
string b;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a[i]>>c[i];
		b+=c[i];
	}
	if(b.size()==1){
		cout<<0;
		return 0;
    }
    bool h=true;
    for(int i=0;i<b.size();i++){
    	if(b[i]!=b[i-1]&&i>0){
    		h=false;
    		break;
		}
	}
	if(h){
		cout<<0;
		return 0;
	}
    if(n%2==0){
    	for(int i=0;i<n/2;i++){
    		if((i==0||f==0)&&b[i]!=b[n-i-1]){
    			ans+=min(a[i],a[n-i-1]);
				if(a[i]>a[n-i-1]){
					f=1;
					cnt=a[i]-a[n-i-1];
					a[i]-=a[n-i-1];
					continue;
				}
				else if(a[n-i-1]>a[i]){
					f=2;
					cnt=a[n-i-1]-a[i];
					a[n-i-1]-=a[i];
					continue;
				}
				else{
					continue;
				}
			}
			else if((i==0||f==0)&&b[i]==b[n-i-1]){
				if(a[i]>a[n-i-1]){
					f=1;
					cnt=a[i]-a[n-i-1];
					a[i]-=a[n-i-1];
					continue;
				}
				else if(a[n-i-1]>a[i]){
					f=2;
					cnt=a[n-i-1]-a[i];
					a[n-i-1]-=a[i];
					continue;
				}
				else{
					continue;
				}
			}
			else if(b[i]!=b[n-i-1]&&b[i]!=b[n-i]&&f==2){
				ans+=min(a[i],a[n-i-1]+cnt);
				if(a[i]>a[n-i-1]+cnt){
					f=1;
					cnt=a[i]-a[n-i-1]-cnt;
					a[i]=a[i]-a[n-i-1]-cnt;
					continue;
				}
				else if(a[n-i-1]+cnt>a[i]){
					f=2;
					cnt=a[n-i-1]+cnt-a[i];
					a[n-i-1]=a[n-i-1]+cnt-a[i];
					continue;
				}
				else{
					continue;
				}
			}
			else if(b[i]!=b[n-i-1]&&b[n-i-1]!=b[i-1]&&f==1){
				ans+=min(a[i]+cnt,a[n-i-1]);
				if(a[i]+cnt>a[n-i-1]){
					f=1;
					cnt=a[i]+cnt-a[n-i-1];
					a[i]=a[i]+cnt-a[n-i-1];
					continue;
				}
				else if(a[n-i-1]>a[i]+cnt){
					f=2;
					cnt=a[n-i-1]-a[i]-cnt;
					a[n-i-1]=a[n-i-1]-a[i]-cnt;
					continue;
				}
				else{
					continue;
				}
			}
			else if(b[i]!=b[n-i-1]&&b[n-i-1]==b[i-1]&&f==1){
				ans+=min(a[i],a[n-i-1]-cnt);
				if(a[i]+cnt>a[n-i-1]){
					f=1;
					cnt=a[i]+cnt-a[n-i-1];
					a[i]=a[i]+cnt-a[n-i-1];
					continue;
				}
				else if(a[n-i-1]>a[i]+cnt){
					f=2;
					cnt=a[n-i-1]-a[i]-cnt;
					a[n-i-1]=a[n-i-1]-a[i]-cnt;
					continue;
				}
				else{
					continue;
				}
			}
			else if(b[i]!=b[n-i-1]&&b[i]==b[n-i]&&f==2){
				ans+=min(a[i]-cnt,a[n-i-1]);
				if(a[i]-cnt>a[n-i-1]){
					f=1;
					cnt=a[i]-a[n-i-1]-cnt;
					a[i]=a[i]-a[n-i-1]-cnt;
					continue;
				}
				else if(a[n-i-1]+cnt>a[i]){
					f=2;
					cnt=a[n-i-1]+cnt-a[i];
					a[n-i-1]=a[n-i-1]+cnt-a[i];
					continue;
				}
				else{
					continue;
				}
			}
			else if(b[i]==b[n-i-1]){
				if(b[i]!=b[n-i]&&f==2){
					ans+=cnt;
					if(a[i]>a[n-i-1]+cnt){
						f=1;
						cnt=a[i]-a[n-i-1]-cnt;
						a[i]=a[i]-a[n-i-1]-cnt;
						continue;
					}
					else if(a[n-i-1]+cnt>a[i]){
						f=2;
						cnt=a[n-i-1]+cnt-a[i];
						a[n-i-1]=a[n-i-1]+cnt-a[i];
						continue;
					}
					else{
						continue;
					}
				}
				else if(b[n-i-1]!=b[i-1]&&f==1){
					ans+=cnt;
					if(a[i]+cnt>a[n-i-1]){
						f=1;
						cnt=a[i]+cnt-a[n-i-1];
						a[i]=a[i]+cnt-a[n-i-1];
						continue;
					}
					else if(a[n-i-1]>a[i]+cnt){
						f=2;
						cnt=a[n-i-1]-a[i]-cnt;
						a[n-i-1]=a[n-i-1]-a[i]-cnt;
						continue;
					}
					else{
						continue;
					}
				}
				else if(b[n-i-1]==b[i-1]&&f==1){
					if(a[i]+cnt>a[n-i-1]){
						f=1;
						cnt=a[i]+cnt-a[n-i-1];
						a[i]=a[i]+cnt-a[n-i-1];
						continue;
					}
					else if(a[n-i-1]>a[i]+cnt){
						f=2;
						cnt=a[n-i-1]-a[i]-cnt;
						a[n-i-1]=a[n-i-1]-a[i]-cnt;
						continue;
					}
					else{
						continue;
					}
				}
				else if(b[i]==b[n-i]&&f==2){
					if(a[i]-cnt>a[n-i-1]){
						f=1;
						cnt=a[i]-a[n-i-1]-cnt;
						a[i]=a[i]-a[n-i-1]-cnt;
						continue;
					}
					else if(a[n-i-1]+cnt>a[i]){
						f=2;
						cnt=a[n-i-1]+cnt-a[i];
						a[n-i-1]=a[n-i-1]+cnt-a[i];
						continue;
					}
					else{
						continue;
					}
				}
			}
		}
	}
	if(n%2!=0){
    	for(int i=0;i<(n-1)/2;i++){
    		if((i==0||f==0)&&b[i]!=b[n-i-1]){
    			ans+=min(a[i],a[n-i-1]);
				if(a[i]>a[n-i-1]){
					f=1;
					cnt=a[i]-a[n-i-1];
					a[i]-=a[n-i-1];
					continue;
				}
				else if(a[n-i-1]>a[i]){
					f=2;
					cnt=a[n-i-1]-a[i];
					a[n-i-1]-=a[i];
					continue;
				}
				else{
					continue;
				}
			}
			else if((i==0||f==0)&&b[i]==b[n-i-1]){
				if(a[i]>a[n-i-1]){
					f=1;
					cnt=a[i]-a[n-i-1];
					a[i]-=a[n-i-1];
					continue;
				}
				else if(a[n-i-1]>a[i]){
					f=2;
					cnt=a[n-i-1]-a[i];
					a[n-i-1]-=a[i];
					continue;
				}
				else{
					continue;
				}
			}
			else if(b[i]!=b[n-i-1]&&b[i]!=b[n-i]&&f==2){
				ans+=min(a[i],a[n-i-1]+cnt);
				if(a[i]>a[n-i-1]+cnt){
					f=1;
					cnt=a[i]-a[n-i-1]-cnt;
					a[i]=a[i]-a[n-i-1]-cnt;
					continue;
				}
				else if(a[n-i-1]+cnt>a[i]){
					f=2;
					cnt=a[n-i-1]+cnt-a[i];
					a[n-i-1]=a[n-i-1]+cnt-a[i];
					continue;
				}
				else{
					continue;
				}
			}
			else if(b[i]!=b[n-i-1]&&b[n-i-1]!=b[i-1]&&f==1){
				ans+=min(a[i]+cnt,a[n-i-1]);
				if(a[i]+cnt>a[n-i-1]){
					f=1;
					cnt=a[i]+cnt-a[n-i-1];
					a[i]=a[i]+cnt-a[n-i-1];
					continue;
				}
				else if(a[n-i-1]>a[i]+cnt){
					f=2;
					cnt=a[n-i-1]-a[i]-cnt;
					a[n-i-1]=a[n-i-1]-a[i]-cnt;
					continue;
				}
				else{
					continue;
				}
			}
			else if(b[i]!=b[n-i-1]&&b[n-i-1]==b[i-1]&&f==1){
				ans+=min(a[i],a[n-i-1]-cnt);
				if(a[i]+cnt>a[n-i-1]){
					f=1;
					cnt=a[i]+cnt-a[n-i-1];
					a[i]=a[i]+cnt-a[n-i-1];
					continue;
				}
				else if(a[n-i-1]>a[i]+cnt){
					f=2;
					cnt=a[n-i-1]-a[i]-cnt;
					a[n-i-1]=a[n-i-1]-a[i]-cnt;
					continue;
				}
				else{
					continue;
				}
			}
			else if(b[i]!=b[n-i-1]&&b[i]==b[n-i]&&f==2){
				ans+=min(a[i]-cnt,a[n-i-1]);
				if(a[i]-cnt>a[n-i-1]){
					f=1;
					cnt=a[i]-a[n-i-1]-cnt;
					a[i]=a[i]-a[n-i-1]-cnt;
					continue;
				}
				else if(a[n-i-1]+cnt>a[i]){
					f=2;
					cnt=a[n-i-1]+cnt-a[i];
					a[n-i-1]=a[n-i-1]+cnt-a[i];
					continue;
				}
				else{
					continue;
				}
			}
			else if(b[i]==b[n-i-1]){
				if(b[i]!=b[n-i]&&f==2){
					ans+=cnt;
					if(a[i]>a[n-i-1]+cnt){
						f=1;
						cnt=a[i]-a[n-i-1]-cnt;
						a[i]=a[i]-a[n-i-1]-cnt;
						continue;
					}
					else if(a[n-i-1]+cnt>a[i]){
						f=2;
						cnt=a[n-i-1]+cnt-a[i];
						a[n-i-1]=a[n-i-1]+cnt-a[i];
						continue;
					}
					else{
						continue;
					}
				}
				else if(b[n-i-1]!=b[i-1]&&f==1){
					ans+=cnt;
					if(a[i]+cnt>a[n-i-1]){
						f=1;
						cnt=a[i]+cnt-a[n-i-1];
						a[i]=a[i]+cnt-a[n-i-1];
						continue;
					}
					else if(a[n-i-1]>a[i]+cnt){
						f=2;
						cnt=a[n-i-1]-a[i]-cnt;
						a[n-i-1]=a[n-i-1]-a[i]-cnt;
						continue;
					}
					else{
						continue;
					}
				}
				else if(b[n-i-1]==b[i-1]&&f==1){
					if(a[i]+cnt>a[n-i-1]){
						f=1;
						cnt=a[i]+cnt-a[n-i-1];
						a[i]=a[i]+cnt-a[n-i-1];
						continue;
					}
					else if(a[n-i-1]>a[i]+cnt){
						f=2;
						cnt=a[n-i-1]-a[i]-cnt;
						a[n-i-1]=a[n-i-1]-a[i]-cnt;
						continue;
					}
					else{
						continue;
					}
				}
				else if(b[i]==b[n-i]&&f==2){
					if(a[i]-cnt>a[n-i-1]){
						f=1;
						cnt=a[i]-a[n-i-1]-cnt;
						a[i]=a[i]-a[n-i-1]-cnt;
						continue;
					}
					else if(a[n-i-1]+cnt>a[i]){
						f=2;
						cnt=a[n-i-1]+cnt-a[i];
						a[n-i-1]=a[n-i-1]+cnt-a[i];
						continue;
					}
					else{
						continue;
					}
				}
			}
		}
	}
	cout<<ans+cnt;
	return 0;
} 
