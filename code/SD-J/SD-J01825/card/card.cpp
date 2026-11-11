#include <bits/stdc++.h>
using namespace std;
long long A[60060],book[60060],n,m,T[60060],cnt[60060];
void check(long long x){
	long long i,j,tot = 0;
	for(i = 1;i < x;i++){
		cnt[A[i]]--;
	}
	for(i = 1;i <= m;i++){
		book[i] = 0;
	}
	for(i = x;i <= n;i++){
		if(book[A[i]] == 0){
			tot++;
			T[tot] = A[i];
			book[A[i]] = tot;
		}
		else{
			for(i = book[A[i]];i <= tot;i++){
				cnt[A[i]]--;
			}
			tot = tot - (tot - book[A[i]] + 1) + 1;
			T[tot] = A[i];
			book[A[i]] = tot;
		}
	}
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long i,j;
	cin>>n>>m;
	for(i = 1;i <= m;i++){
		cnt[i] = 0;
	}
	for(i = 1;i <= n;i++){
		cin>>A[i];
		cnt[A[i]] += n;
	}
	for(i = 1;i <= n;i++){
		check(i);
	}
	for(i = 1;i <= m;i++){
		cout<<cnt[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
