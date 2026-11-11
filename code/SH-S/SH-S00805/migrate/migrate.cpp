#include<bits/stdc++.h>
using namespace std;
int c,T;
long long fastread(){
	long long ch=getchar();
	long long t=0,check=1;
	if(ch=='-'){
		check=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		t=t*10+ch-('0');
		ch=getchar();
	}
	return t*check;
}
int fastprint(long long x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9){
		fastprint(x/10);
	}
	char ch=x%10+'0';
	putchar(ch);
} 
int solve(){
	int n=fastread(),island[305],ans=0;
		long long d=fastread();
		for(int i=1;i<=n;i++){
			island[i]=fastread();
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				//cout<<i<<" "<<j<<endl;
				int cnt=0;
				int sum=0;
				bool check=0; 
				long long last=island[i],locate=i;
				for(int k=i+1;k<=j+1;k++){
					//cout<<last<<endl;
					if(island[k]-last<=d&&k-1!=j){
						continue;
					}
					else{
						if(island[k-1]-island[k-2]>d){
							check=0;
							break;
						}
						if(last!=island[k-1]||(last==island[k-1]&&k==j&&island[k]-last<=d)){
							sum++;
							//cout<<locate<<" "<<k<<endl;
							last=island[k-1];
							if(locate-1>i&&last-island[locate-1]<=d){
								cnt++;
								check=1;
							}
							if(locate-2>i&&last-island[locate-2]<=d){
								check=0;
								break;
							}
							if(cnt>1){
								check=0;
								break;
							}
							locate=k-1;
						}
						else {
							sum=-1;
							check=0;
							break;
						}
						
					}
				}
				//cout<<sum<<" "<<cnt<<" "<<check<<endl;
				if(check&&cnt==1){
					ans++;
					//cout<<i<<" "<<j<<endl;
				}
				//cout<<endl;
			}
		}
		fastprint(ans);
		printf("\n");
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=fastread(),T=fastread();
	for(int z=1;z<=T;z++){
		solve();
	}
	return 0;
}
