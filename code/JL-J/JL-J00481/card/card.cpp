#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int s[200];
	int n,a,b;
	cin>>n;
	for(int i=0;i<=n;i++){
        cin>>s[i];
        if(s[i]%2==1){
            a++;
        }
        else{
            b++;
        }
	}
}

