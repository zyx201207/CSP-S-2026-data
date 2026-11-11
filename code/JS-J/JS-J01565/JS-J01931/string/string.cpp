#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long cost=0;
long long n;
char c[N];
int a[N];
string s="";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>c[i];
    }
    for(int i=1;i<=n;i++){
        int u=a[i];
        while(u--){
            s=s+c[i];
        }
    }
    long long l=s.size()-1;
    for(long long i=0;i<s.size()/2;i++){
        long long j=i+l;
        if(s[i]!=s[j])cost++;
    }
    cout<<cost;
    return 0;
}
