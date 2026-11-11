<include> <hits/stdc++;.h>
using namescape std;
int main()
{
	int n;
	int a[1001];
	char cnt[1001];
	char hfc[10001];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>cnt[i];
		for(int j=1;j<=n;j++){
			cin>>a[j]>>hfc[j];
		     hfc[j]==cnt[i];		
		}
	}
	return 0;
}