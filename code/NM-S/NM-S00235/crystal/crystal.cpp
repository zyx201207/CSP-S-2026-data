#include<iostream>
#include<algorithm>
unsigned long long cs[500005];
using namespace std;
int main(){
    //freopen("crystal.in","r",stdin);
    //freopen("crystal.out","w",stdout);
    int n;
    cin>>n;
    unsigned long long m;
    cin>>m;
    for(int i=0;i<n;i++){
        cin>>cs[i];
    }
    sort(cs,cs+n);
    if(m==0){
        int a[500005]={0};
        for(int i=0;i<n;i++){
            a[cs[i]]++;
        }
        int maxn=0;
        for(unsigned long long i=1;i<cs[n-1];i++){
            maxn=max(maxn,a[i]);
        }
        cout<<maxn;
    }
    else{
        if(m==1){
            int a[500005]={0};
			for(int i=0;i<n;i++){
				a[cs[i]]++;
			}
			int maxn=0;
			for(unsigned long long i=1;i<cs[n-1];i++){
				maxn=max(maxn,a[i]);
			}
			int status=0;
			for(unsigned long long i=1;i<cs[n-1];i++){
				if(a[i]==maxn){
					for(int j=0;j<n;j++){
						if(cs[j]==i-1){
							cout<<maxn+1;
							status=1;
							break;
						}
					}
					if(status==1){
						break;
					}
				}
			}
        }
        else{
            int exit=0;
            for(int i=1;i<n-1;i++){
                if(cs[i]-cs[i-1]!=cs[i+1]-cs[i]){
                    exit=1;
                    break;
                }
            }
            if(exit==0){
                int ans=1;
                for(int i=n-2;i>=0;i--){
                    if(m>(cs[n-1]-cs[i])){
                        ans++;
                        m-=(cs[n-1]-cs[i]);
                    }
                    else{
                        break;
                    }
                }
                cout<<ans;
            }
            else{
                cout<<cs[3]-cs[2];
            }
        }
    }
    return 0;
}
