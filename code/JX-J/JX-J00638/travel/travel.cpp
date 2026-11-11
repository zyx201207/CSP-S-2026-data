#include<bits/stdc++.h>
using namespace std;
int ans[10];
string a[1000],b[1000];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=2;i++){
        cin>>a[i]>>b[i];
	}
	for(int i=1;i<=4;i++){
        ans[i]=0;
	}
	if(a[1]==a[2]){
        ans[1]=1;
        if(b[1][1]==b[2][1]&&b[1][2]==b[2][2]){
            ans[2]=1;
            if((b[1][3]>'C'&&b[2][3]>'C')||(b[1][3]<'D'&&b[2][3]<'D')){
                ans[3]=1;
                if((b[1][3]-b[2][3])*(b[1][3]-b[2][3])==1){
                    ans[4]=1;
                }
            }
        }
    }
    for(int i=1;i<=4;i++){
        cout<<ans[i];
	}
	return 0;
}

