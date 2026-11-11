#include<bits/stdc++.h>
using namespace std;
longlong m,n;
int a[500005];

int main(){
	freopen("hub.in",'r',stdin);
	freopen("hub.out",'w',stdout);
	ios::sync_with_stdio("false");
	cin.tie(0);
    cin>>n>>m;
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    a.sort();
    int cha[500005];
    for(int i = 0;i<n-1;i++){
        cha[i]=a[i+1]-a[i];
    }
    int flag = 1;
    int i = 2;
    int mi = 2;
    while(flag==1){
        for(int j = 0;j+i<n-1;j++){
            int ans = 0;
            for(int z = 0;z<i;z++){
                ans += cha[j]*(z+1);
            }
            if(ans<=m)mi=max(i,mi);
        }
        if(i==n-1)flag = 0;
        i++;

    }
    cout<<mi;
    return 0;
}
