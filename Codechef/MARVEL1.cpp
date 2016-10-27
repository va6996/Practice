#include <iostream>
using namespace std

long int cash[100000];

int main() {
	int t;
	cin>>t;
	while(t--){
		int n, m;
		cin>>n>>m;
		for(int i=0;i<n;i++)
			cash[i]=1000000000;
		for(int i=0;i<m;i++){
			int c;
			cin>>c;
			if(c){
				int p, q;
				long int val;
				cin>>val>>p>>q;
				for(int j=p-1;j<q;j++){
					if(cash[j]>0)
						if(cash[j]-val>=0)
							cash[j] -= val;
						else
							cash[j]=0;
				}
			}
			else{
				int p, q, minv = 0;
				cin>>p>>q;
				for(int j=p-1;j<q;j++){
					if(cash[j]>minv)
						minv=cash[j];
				}
				cout<<minv<<endl;
			}
		}
	}
	return 0;
}