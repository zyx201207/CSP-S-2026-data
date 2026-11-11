#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[214514];
bool cmd(long long deltaforce,long long b){
    return deltaforce>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmd);
    long long anns=a[1];
    for(int i=2;i<=m;i++){
        anns=anns&a[i];
    }
    cout<<anns;
	return 0;
}
/*
zhe ti dou hao shui a
wo tiao zhan AK
4 2
3 15 12 12
lai -j zha yu de 
ni bu zha, wo bu zha, yu er he shi neng zhang da
5 3
31 3 1 15 7
da le yi dui dai ma fa xian shi gun mu de jiu shu gan
bingbingbing
ice ice ice
*/