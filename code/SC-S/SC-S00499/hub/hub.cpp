#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	srand(time(0));
	int c,t;
	cin>>c>>t;
	while(t--){
		cout<<rand()%10+1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}