#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n;
	cin>>m>>n;
	vector<int> a(n);
	for(int i=1;i<=m;i++){
		cin>>a[i];
		if(m==1 && a[i]==n){
			cout<<"1";
			return 0;
	}
	else{
		cout<<"0";
		return 0;
	}
}
	cout<<n+7<<" "<<n<<" "<<n;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
