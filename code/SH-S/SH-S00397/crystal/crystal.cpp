#include<bits/stdc++.h>
using namespace std;
const int MAX_N=5e5+10;
int N;
int Ans=0;
long long M;
long long A[MAX_N];
long long Minus[MAX_N];
long long SumMinus[MAX_N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>N>>M;
	for(int i = 1;i<=N;i++){cin>>A[i];}
	sort(1+A,1+A+N);
	
	for(int i = 2;i<=N;i++){Minus[i]=A[i]-A[i-1];}
	for(int i = N;i>=2;i--){SumMinus[i]=SumMinus[i+1]+Minus[i];}
	int Left=1,Score=0,LastS=0;
	for(int i = 2;i<=N;i++){
		Score=LastS+(i-Left)*Minus[i];
		if(Score<=M){Ans=max(Ans,i-Left+1);}
		else{
			while(Score>M){Score-=SumMinus[Left+1]-SumMinus[i+1];Left++;}
		}
		LastS=Score;
	}
	cout<<Ans;
	return 0;
} 
