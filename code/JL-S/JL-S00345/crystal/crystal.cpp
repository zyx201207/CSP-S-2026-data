
#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	int n,m;

	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}

	for(int i=1;i<=n-1;i++)
	{
        for(int j=1;j<=n-i,j++)
        {
            if(a[j]>a[j+1])
            {
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
	}
	int ans=1;
	for(int i=n;i>=ans;i--)
	{
        int ans1=1,m1=m;
        for(int j=i;j>=2;j--)
        {

            if(m1>=a[i]-a[j-1])
            {
                m1-=a[i]-a[j-1];
                ans1++;
                if(ans1>ans)
                ans=ans1;
            }
            else{
            break;
            }

        }
	}
	cout<<ans;





	fclose(stdin);
	fclose(stdout);


	return 0;
	}
