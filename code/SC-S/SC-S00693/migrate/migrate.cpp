#include<bits/stdc++.h> 
using namespace std;
int count1,c,t,n,d,a[2000005],way[2000005];
bool k[2000005],k1[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	if(c>=11&&c<=12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i]; 
			}int m=d/(a[2]-a[1]);
			cout<<n-2*m+1;
		}
	}else{
		while(t--){
		count1 =0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}if(n<=3){
			cout<<0<<"\n";
			continue;
		}else{
			int p=2;
			for(int i=1;i<=n;){
				if(p<=n&&a[p+1]-a[i]<=d){
					p++;
					way[i]++;
				}else{
					i++;
					way[i]=way[i-1]-1;
				}
			}
			for(int i=n;i>3;i--){
				for(int j=i-3;j>=1;j--){
					if(way[j]==0||way[j]==1){
						continue;
					}else{
						if(way[j]=way[j+1]+1){
							k[j]=k[j+1];
							if(k[j])count1++;
							continue;
						}if(way[j]==2&&way[j+1]-way[j+2]==1&&k[j+1]==0){
							k[j]=1;
							count1+=1;
							continue;
						}int num;
						for(int k2=1;k2<=way[j];k2++){
							if(k[k2+j])num++;
						}if(num==0){
							k[j]=1;
							count1++;
						}
					}
				}
			}
		}cout<<count1<<"\n";
	} 
	}
	return 0;
}