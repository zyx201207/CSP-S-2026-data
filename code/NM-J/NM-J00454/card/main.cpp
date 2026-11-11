#include <iostream>

using namespace std;

int main()
{
    freopen("travel.in","r",stdin);

    freopen("travel.out","w",stdout);

    int n,m;

    cin>>n>>m;

    long long a[n];

    long long b[n];

    for(int i=0;i<n;i++){

    	a[i]=b[i];

	}


	long long sum[n]={};

    for(int i=0;i<m;i++){

      cin>>a[i];

    }


	for(int i=0;i<n;i++){

		for(int j=0;j<n;j++){

			if(a[i]=b[j]){

				for(int k=0;k<n;k++){

					if(k<i){

						sum[k]=0;

					}

				}

			}

		}

	}


    for(int i=0;i<n;i++){

    	if(sum[i]!=0){

    		cout<<sum[i]<<" ";

		}

	}

    return 0;

}
