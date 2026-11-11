#include <bits/stdc++.h>
using namespace std;
int A[200500],B[100500],book[100500],book1[100500];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,i,j,o,k;
	cin>>n>>m;
	for(i = 1;i <= n;i++){
		cin>>A[i]; 
	}
	for(i = 1;i <= n;i++){
		o = 1;
		for(j = i;j <= n;j++){
			B[o] = A[j];
			o++;
			if(book[A[j]] == 1){
				for(k = o;k >= 1;k++){
					if(B[k] != A[j]) B[k] = 0;
					else break;
				}
				for(o = 1;o <= m;o++){
					book[m] = 0;
				}
				o = k;
			}
			else book[A[j]] = 1;
		}
		for(j = 1;j <= m;j++){ 
			B[j] = 0;
			if(book[j] == 1){
				book1[j]++;
				book[j] = 0;
			}
		}
	}
	for(i = 1;i <= m;i++){
		cout<<book1[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
