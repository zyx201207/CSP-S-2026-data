#include<bits/stdc++.h>
using namespace std;
pair<int,char>a[200005];
long long ans=0;
//long long!!!!!!!!!!!!!!!!!!!!!!!!!!!!
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i].first>>a[i].second;
	int l=1,r=n;
	while(l<r){
        if(a[l].second==a[r].second){
            if(a[l].first>a[r].first){
                a[l].first-=a[r].first;r--;
            }
            else if(a[r].first>a[l].first){
                a[r].first-=a[l].first;l++;
            }
            else if(a[r].first==a[l].first){
                r--;l++;
            }
        }
        if(a[l].second!=a[r].second){
            if(a[l].first>a[r].first){
                ans+=a[r].first;a[l].first-=a[r].first;r--;
            }
            else if(a[r].first>a[l].first){
                ans+=a[l].first;a[r].first-=a[l].first;l++;
            }
            else if(a[r].first==a[l].first){
                ans+=a[r].first;r--;l++;
            }
        }
	}
	cout<<ans;
	return 0;
}
