#include<bits/stdc++.h>
using namespace std;
long long c,L[200001],l,n,le,ri;char S[200001];
int main(){
	freopen(stdin,'r',"and.in");
	freopen(stdout,'w',"and.ans");
	cin>>n;ri=n-1;
	for(int i=0;i<n;i++){cin>>L[i]>>S[i];l+=L[i];}
	while(le<=ri){if(S[le]!=S[ri]){c+=min(L[le],L[ri]);if(L[le]>L[ri]){L[le]-=L[ri];ri--;}else if(L[le]<L[ri]){L[ri]-=L[le];le++;}else{le++;ri--;}}else{if(L[le]>L[ri]){L[le]-=L[ri];ri--;}else if(L[le]<L[ri]){L[ri]-=L[le];le++;}else{le++;ri--;}}}
	cout<<c;
	return 0;
}
