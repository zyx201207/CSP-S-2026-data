#include <iostream>
using namespace std;
typedef long long ll;
const int N = 2000005, M = 5005;
const ll Inf = 2e18;
ll X[N], F[M][M], C[M][M];

void Solve() {
	int n;ll d;	cin>>n>>d;
	for(int i=1;i<=n;i++)	cin>>X[i];
	
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)	F[i][j]=Inf, C[i][j]=0;
	for(int i=1;i<=n;i++) if(X[i+1]-X[i]<=d)	F[i][i+1]=C[i][i+1]=1;
	
	for(int len=2;len<=n;len++)
		for(int i=1, j=len;j<=n;i++, j++) {
			if(X[j]-X[i]<=d) {F[i][j]=1, C[i][j]=1;continue;}
			
			for(int k=i+1;k<=j-1 && X[k]-X[i]<=d;k++)
				if(F[i][j]==F[k][j]+1)	C[i][j]+=C[i][k]*C[k][j];
				else if(F[i][j]>F[k][j]+1)
					F[i][j]=F[i][k]+F[k][j], C[i][j]=C[i][k]*C[k][j];
		}
	
	int Ans=0;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)	Ans+=(C[i][j]==2);
	cout<<Ans<<endl;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int TestID, T;	cin>>TestID>>T;	while(T--)	Solve();
	return 0;
}
