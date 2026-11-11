#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+5;
const int M = 3e5+5;
int n,m,a[N],b[N];
int tonD[N],tonA[N];
int ju=1,pai;
int desktop[N];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	while(n--){
            pai=0;
		for(int i=1;i<=n;i++)b[i]=a[i];
		for(int i=ju;i<=n;i++){
			if(tonD[b[i]]==0){
                desktop[pai++]=b[i];
                tonD[b[i]]++;
            }else{//else 龙卷风摧毁停车场

                int st=1;
                while(desktop[st]!=b[i])st++;
                for(int j=st;j<=sizeof(desktop);j++)tonD[desktop[j]]--;
                for(int j=st;j<=sizeof(desktop);j++)desktop[j]=0;
            }
		}
        if(tonD[a[ju]]>0)tonA[a[ju]]++;
        ju++;
	}
	cout<<tonA[a[ju]];
	return 0;
}/*
10 3
3 1 2 1 3 2 3 1 2 1


*/
