#pragma once
using std::cout;
using std::cin;
using std::cerr;
using std::endl;

using std::ofstream;

using std::setprecision;

using std::fabs;

using std::clock;

namespace MemoryAllocation {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(292, 273);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			clock_t outTime , inTime;
			ofstream outFile("c:/stats.txt");	// variables required for measuring and storing the results.

			unsigned int order = 0;	// variables needed for the program itself.
			double *A;

			outTime = clock();

			for(order = 1000 ; order <= 6000 ; order += 20)
			{
				inTime = clock();
				A = new double[order*order];
				/*for(int c = 0 ; c < order*order ; ++c)
					A[c] = c;*/
				delete[] A;
				outFile<<clock()-inTime<<endl;
			}

			outFile<<"\n\n"<<clock()-outTime<<endl;			
		}

	};
}

