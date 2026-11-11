#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int n;
ll ans;
int a[N];
char ch[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
        cin>>a[i]>>ch[i];
	}
	int l=1,r=n;
	while(l<r){
        if(ch[l]!=ch[r]){
            if(a[l]<a[r]){
                ans+=a[l];
                a[r]-=a[l];
                l++;
            }else if(a[l]>a[r]){
                ans+=a[r];
                a[l]-=a[r];
                r--;
            }else{
                ans+=a[l];
                l++,r--;
            }
        }else{
            if(a[l]<a[r]){
                a[r]-=a[l];
                l++;

            }else if(a[l]>a[r]){
                a[l]-=a[r];
                r--;
            }else{
                l++,r--;
            }
        }
	}
	cout<<ans<<"\n";
	return 0;
}

