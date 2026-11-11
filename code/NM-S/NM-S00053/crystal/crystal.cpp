#include<bits/stdc++.h>
using namespace std;

int main(){

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin.tie(nullptr);

    int n;
    long long m;
    cin>>n>>m;

    int a[500002];
    double g=0,j;
    for(int j =1;j<=n;j++){
        cin>>a[j];
        g=g+a[j];
    }
    j=g/n;

    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(a[i]>a[j]){
                int k;
                k=a[i];
                a[i]=a[j];
                a[j]=k;
            }
        }
    }

	double y=0x7f7f7f;
	int q;
	for(int i=1;i<=n;i++){
        double x;
        x=a[i]-j;
        if(x<0) x=-x;
        if(x<=y){
            y=x;
            q=i;
        }
	}

	int z=q;
    while(m>0){
        m=m-(a[q]-a[z]);
        z--;
    }

    cout<<q-z;

    fclose(stdin);fclose(stdout);
    return 0;

}
