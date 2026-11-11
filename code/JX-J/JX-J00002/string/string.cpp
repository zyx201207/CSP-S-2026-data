#include<bits/stdc++.h>
using namespace std;
string s="";
long long hw(){
    long long sum=0;
    for(int i=0,j=s.size()-1;i<=j,j>=i;i++,j--){
        if(s[i]!=s[j])sum++;
    }
    return sum;
}
int main(){
	freopen("string6.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
        int a;
        char c;
        cin>>a>>c;
        for(int j=1;j<=a;j++){
            s+=c;
        }
	}
	cout<<hw();
	return 0;
}
