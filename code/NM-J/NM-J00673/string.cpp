#include<bits/stdc++.h>
using namespace std;
char s[9999999999];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int num=0;
    int shu;
    char c;
    int sum=0;
    for (int i=1;i<=n;i++){
    	cin>>shu;
    	cin>>c;
        for (int i=sum+1;i<=sum+shu;i++){
    	    s[i]=c;
	    }
	    sum+=shu;
	}
	int m,ans=0;
    m=sum/2;
	for (int i=1;i<=m;i++){
		if (s[i]!=s[sum-i+1]){
			ans++;
		}
	}
	cout<<ans+1;

    return 0;


}
