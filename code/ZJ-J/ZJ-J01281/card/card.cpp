#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010];
int desk[500010];
int ans[300010];
int cnt[300010];
int cntt=0;
int main(){
	//freopen("Kards.in","r",stdin);
	//freopen("Kards.out","w",stdout);
	//cout<<"1939";
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	int OK_A=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])OK_A=0;
	}
	if(m==1)cout<<n;
	if(OK_A){
		for(int i=1;i<=n;i++){
			cnt[a[i]]++;
		}
		for(int i=0;i<n;i++){
			cnt[a[i]]--;
			for(int i=1;i<=m;i++){
				if(cnt[i])ans[i]++;
			}
		}
		for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	}else{
		for(int i=1;i<=n;i++){
			memset(desk,0,sizeof desk);
			for(int j=i;j<=n;j++){
				int f=1;
				for(int k=1;k<=cntt;k++){
					if(desk[k]==a[j]){
						cntt=k;
						f=0;
						break;
					}
				}if(f){
					cntt++;
					desk[cntt]=a[j];
				}
			}
			for(int j=1;j<=cntt;j++){
				ans[desk[j]]++;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<' ';
		}
	}
	
	return 0;
}
/*
#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int sum[13][11];
char map_[13][11]={
	{'.','.','.','.','.','.','.','.','.','.','.',},
	{'.','.','.','.','.','.','.','.','.','.','.',},
	{'.','.','.','.','.','^','.','.','.','.','.',},
	{'.','.','.','.','.','.','.','.','.','.','.',},
	{'.','.','.','.','^','.','^','.','.','.','.',},
	{'.','.','.','.','.','.','.','.','.','.','.',},
	{'.','.','.','^','.','^','.','^','.','.','.',},
	{'.','.','.','.','.','.','.','.','.','.','.',},
	{'.','.','^','.','^','.','^','.','^','.','.',},
	{'.','.','.','.','.','.','.','.','.','.','.',},
	{'.','^','.','^','.','^','.','^','.','^','.',},
	{'.','.','.','.','.','.','.','.','.','.','.',},
	{'.','.','.','.','.','.','.','.','.','.','.',}
};
int fen(int x){
	int sum=0;
	for(int i=1;i<=x;i++){
		sum+=rand()%2;
	}
	return sum;
}
void draw(){
	for(int i=0;i<13;i++){
		for(int j=0;j<11;j++){
			if(sum[i][j])cout<<sum[i][j];
			else cout<<map_[i][j];
			if(sum[i][j]<10)cout<<' ';
			cout<<' ';
		}cout<<'\n';
	}
}
int main(){
	srand(time(0));
	sum[0][5]=80;
	for(int i=0;i<12;i++){
		system("cls");
		draw();
		for(int j=0;j<11;j++){
			if(sum[i][j]){
				if(map_[i+1][j]=='^'){
					int f=fen(sum[i][j]);
					sum[i+1][j-1]+=f;
					sum[i+1][j+1]+=sum[i][j]-f;
					sum[i][j]=0;
				}else{
					sum[i+1][j]+=sum[i][j];
					sum[i][j]=0;
				}
			}
		}
		Sleep(666);
	}
	draw();
	return 0;
}
*/