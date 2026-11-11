#include <bits/stdc++.h>
using namespace std;
constexpr int N=2e5+5;
int n,a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        if(c[i]==c[i-1]) a[i-1]+=a[i],c[i]=0,i--,n--;
    }
    /*
    cout<<n<<'\n';
    for(int i=1;i<=n;i++) cout<<a[i]<<' '<<c[i]<<'\n';
    cout<<endl;
    */
    long long ans=0;
    for(int i=1,j=n;i<j;){
        while(c[i]==c[j]){
            a[i]-=min(a[i],a[j]),a[j]-=min(a[i],a[j]);
            if(a[i]==0) i++;
            if(a[j]==0) j--;
        }
        if(a[i]==a[j]&&c[i]!=c[j])ans+=a[i],a[i]=0,a[j]=0,i++,j--;
        if(a[i]>a[j]){
            ans+=a[j],a[i]-=a[j],a[j]=0;j--;
        }else{
            ans+=a[i],a[j]-=a[i],a[i]=0,i++;
        }
    }
    cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
