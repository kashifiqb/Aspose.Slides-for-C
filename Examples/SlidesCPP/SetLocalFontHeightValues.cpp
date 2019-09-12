
#include <DOM/Presentation.h>
#include <DOM/ISlideCollection.h>
#include <DOM/IMasterSlideCollection.h>
#include <DOM/IMasterSlide.h>
#include <DOM/IShapeCollection.h>
#include <DOM/ShapeType.h>
#include <DOM/ITextFrameFormat.h>
#include <DOM/AutoShape.h>
#include <DOM/ITextFrame.h>
#include <DOM/IPortionCollection.h>
#include <DOM/IPortion.h>
#include <DOM/IPortionFormat.h>
#include <DOM/IParagraphCollection.h>
#include <DOM/IParagraph.h>
#include <DOM/IParagraphFormat.h>
#include <DOM/Portion.h>
#include <DOM/IPortionFormatEffectiveData.h>
#include <DOM/ITextStyle.h>

#include <Export/SaveFormat.h>

#include <system/string.h>
#include <system/console.h>

#include "SlidesExamples.h"

using namespace Aspose::Slides;
using namespace System;

void SetLocalFontHeightValues() 
{

	// ExStart:SetLocalFontHeightValues
	// The path to the documents directory.
	const String outPath = u"../out/SetLocalFontHeightValues.pptx";

	System::SharedPtr<Presentation> pres = System::MakeObject<Presentation>();
	System::SharedPtr<IAutoShape> newShape = pres->get_Slides()->idx_get(0)->get_Shapes()->AddAutoShape(Aspose::Slides::ShapeType::Rectangle, 100.0f, 100.0f, 400.0f, 75.0f, false);
	newShape->AddTextFrame(u"");
	newShape->get_TextFrame()->get_Paragraphs()->idx_get(0)->get_Portions()->Clear();

	System::SharedPtr<IPortion> portion0 = System::MakeObject<Portion>(u"Sample text with first portion");
	System::SharedPtr<IPortion> portion1 = System::MakeObject<Portion>(u" and second portion.");

	newShape->get_TextFrame()->get_Paragraphs()->idx_get(0)->get_Portions()->Add(portion0);
	newShape->get_TextFrame()->get_Paragraphs()->idx_get(0)->get_Portions()->Add(portion1);

	System::Console::WriteLine(u"Effective font height just after creation:");
	System::Console::WriteLine(System::String(u"Portion #0: ") + portion0->get_PortionFormat()->GetEffective()->get_FontHeight());
	System::Console::WriteLine(System::String(u"Portion #1: ") + portion1->get_PortionFormat()->GetEffective()->get_FontHeight());

	pres->get_DefaultTextStyle()->GetLevel(0)->get_DefaultPortionFormat()->set_FontHeight(24.0f);
	System::Console::WriteLine(u"Effective font height after setting entire presentation default font height:");
	System::Console::WriteLine(System::String(u"Portion #0: ") + portion0->get_PortionFormat()->GetEffective()->get_FontHeight());
	System::Console::WriteLine(System::String(u"Portion #1: ") + portion1->get_PortionFormat()->GetEffective()->get_FontHeight());

	newShape->get_TextFrame()->get_Paragraphs()->idx_get(0)->get_ParagraphFormat()->get_DefaultPortionFormat()->set_FontHeight(40.0f);
	System::Console::WriteLine(u"Effective font height after setting paragraph default font height:");
	System::Console::WriteLine(System::String(u"Portion #0: ") + portion0->get_PortionFormat()->GetEffective()->get_FontHeight());
	System::Console::WriteLine(System::String(u"Portion #1: ") + portion1->get_PortionFormat()->GetEffective()->get_FontHeight());

	newShape->get_TextFrame()->get_Paragraphs()->idx_get(0)->get_Portions()->idx_get(0)->get_PortionFormat()->set_FontHeight(55.0f);
	System::Console::WriteLine(u"Effective font height after setting portion #0 font height:");
	System::Console::WriteLine(System::String(u"Portion #0: ") + portion0->get_PortionFormat()->GetEffective()->get_FontHeight());
	System::Console::WriteLine(System::String(u"Portion #1: ") + portion1->get_PortionFormat()->GetEffective()->get_FontHeight());

	newShape->get_TextFrame()->get_Paragraphs()->idx_get(0)->get_Portions()->idx_get(1)->get_PortionFormat()->set_FontHeight(18.0f);
	System::Console::WriteLine(u"Effective font height after setting portion #1 font height:");
	System::Console::WriteLine(System::String(u"Portion #0: ") + portion0->get_PortionFormat()->GetEffective()->get_FontHeight());
	System::Console::WriteLine(System::String(u"Portion #1: ") + portion1->get_PortionFormat()->GetEffective()->get_FontHeight());


	pres->Save(outPath, Aspose::Slides::Export::SaveFormat::Pptx);
	// ExEnd:SetLocalFontHeightValues

}