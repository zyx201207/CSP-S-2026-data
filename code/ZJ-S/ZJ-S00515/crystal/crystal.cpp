#include<bits/stdc++.h>
using namespace std;
long long j,ans,cnt,a[505005],k[505005],m,n,h,kill;
int main(){
    ios::sync_with_stdio(false);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);//记得删除
	cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];//输入数据
    }
    sort(a+1,a+1+n);//单调递增
    a[0]=0;
    h=0;
    for(int i=1;i<=n;i++){
    	k[i]=a[i+1]-a[i];
    	k[i]=k[i]+k[i-1];//伪装前缀和
    	if(k[i]-k[i-1]!=0){
    		cnt=i-h;//统计不用加成的
    		j=1;
    		kill=k[h]-k[h-1];
    		while((kill<=m)&&(h-j)>=0){
    			cnt++;
    			j++;
    			kill+=(k[h]-k[h-j]);
			}
			ans=max(ans,cnt);
			h=i;
		}
	}
	cout<<ans;
    return 0;
}